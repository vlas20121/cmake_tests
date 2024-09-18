#include <iostream>
#include <cctype>
#include <list>
#include <string>
#include <assert.h>
#include <map>
#include <utility>
#include <vector>

using namespace std;

template<class NUMBER>
bool in_range(NUMBER v, NUMBER v0, NUMBER v1)
{
    return (v0 <= v) && (v <= v1);
}

namespace parser
{
	/// <summary>
	/// space (0x20, ' ')
    /// form feed(0x0c, '\f')
    /// line feed(0x0a, '\n')
    /// carriage return (0x0d, '\r')
    /// horizontal tab(0x09, '\t')
    /// vertical tab(0x0b, '\v')
	/// </summary>
	/// <param name="ch"></param>
	/// <returns></returns>
	bool is_space(char ch)
	{
    		return std::isspace(static_cast<unsigned char>(ch));
	}
    bool is_alpha_rus(unsigned char ch)
    {
        //CP866
        //ј-я=192-223
        //a-€=224-255 

        //ASCII + Windows 1251
        //ј-я=192-223
        if (in_range((int)ch, 192, 223))
            return true;
        //a-€=224-255 
        if (in_range((int)ch, 224, 255))
            return true;
        return false;
    }
    /// <summary>
    /// digits (0123456789)
    /// uppercase letters(ABCDEFGHIJKLMNOPQRSTUVWXYZ)
    /// lowercase letters(abcdefghijklmnopqrstuvwxyz)
    /// </summary>
    /// <param name="ch"></param>
    /// <returns></returns>
    bool is_alnum(char ch)
    {
        auto chu=static_cast<unsigned char>(ch);
        if (is_alpha_rus(chu))
            return true;
        return std::isalnum(static_cast<unsigned char>(chu));
    }
    bool is_digit(char ch)
    {
        return std::isdigit(static_cast<unsigned char>(ch));
    }
    /// <summary>
    /// (!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
    /// </summary>
    /// <param name="ch"></param>
    /// <returns></returns>
    bool is_punct(char ch)
    {
        if (ch == 'Ч')
            return true;
        return std::ispunct(static_cast<unsigned char>(ch));
    }
    struct stream_tocken
    {
        const string s;
        int pos = 0;

        bool eof()
        {
            return pos >= s.size();
        }
        char next_char()
        {
            assert(!eof());
            return s[pos++];
        }
        void pushback_last()
        {
            pos--;
        }
        string next()
        {
            if(eof())
                return "";
            char ch = next_char();
            if (is_punct(ch))
            {
                return string(1, ch);
            }
            else if (is_space(ch))
            {
                for (;;)
                {
                    if (eof())
                        return " ";
                    ch = next_char();
                    if (!is_space(ch))
                    {
                        pushback_last();
                        return " ";
                    }
                }
            }
            else if (is_alnum(ch))
            {
                string tocken;
                tocken.push_back(ch);
                for (;;)
                {
                    if (eof())
                        return tocken;
                    ch = next_char();
                    if (is_alnum(ch))
                        tocken.push_back(ch);
                    else
                        {
                            pushback_last();
                            return tocken;
                        }
                }
            }
            else {
                assert(false);
                return "";
            }
        }
    };
    list<string> parse(const string& s)
    {
        stream_tocken stream{ s };
        list<string> tockens;
        for (string cur = stream.next(); !cur.empty(); cur = stream.next())
        {
            if(cur!=" ")
                tockens.push_back(cur);
        }
        return tockens;
    }
}

class text_gen {
public:
    using id = int;
    using count = int;
    using _id2word = vector<string>;        ///id -> word, word=id2word[id]
    using _id2count = vector<count>;        ///id -> count, count=id2count[id]
    using follow_ids = map<id, count>;
    using _id2followids = vector<follow_ids>; ///id -> map<id, count>
    using _word2id = map<string, id>;       ///word -> id
public:
    _id2word id2word;
    _id2count id2count;
    _id2followids id2followids;
    _word2id word2id;
public:
    id add_word(const string& s)
    {
        auto search = word2id.find(s);
        if (search == word2id.end())
        {
            id new_id = (id)id2word.size();
            id2word.push_back(s);
            id2count.push_back(1);
            id2followids.push_back(follow_ids());
            word2id[s] = new_id;
            return new_id;
        }
        else
        {
            id old_id = search->second;
            id2count[old_id]++;
            return old_id;
        }
    }
    void add_follow(follow_ids& f, id id)
    {
        auto search = f.find(id);
        if (search == f.end())
            f[id] = 1;
        else
            search->second++;
    }
    void add_word_pair(id id0, id id1)
    {
        add_follow(id2followids[id0], id1);
    }
    void init(const string& s)
    {
        auto res = parser::parse(s);
        id id_prev = -1;
        for (auto w : res)
        {
            id cur_id=add_word(w);
            if(id_prev>=0)
                add_word_pair(id_prev, cur_id);
            id_prev = cur_id;
        }
    }

    //prepare дл€ быстрой генерации:
    using _id2sum_count = vector<count>;      //id -> суммарное количество всех фолловеров
    using _fol_dict = vector<pair<id, count>>; //unsorted id -> count
    using _id2fol_dict = vector<_fol_dict>;    //id -> частотный словарь фолловеров по идам
    _id2sum_count id2fol_count;
    _id2fol_dict id2fol_dict;

    void prepare()
    {
        for (id _id = 0; _id < id2followids.size(); _id++)
        {
            const follow_ids& fd = id2followids[_id];//follow_ids = map<id, count>;
            count sum = 0;
            _fol_dict fol_dict;
            for (const auto& _pair : fd)
            {
                id _id1 = _pair.first;
                count _count = _pair.second;
                sum += _count;
                fol_dict.push_back(pair<id,count>(_id1,_count));
            }
            id2fol_count.push_back(sum);
            id2fol_dict.push_back(fol_dict);
        }
        ///convert id2followids into sorted vector of pairs
    }
    id random_next(const _fol_dict& dic,count c)
    {
        if (c == 0)
            return -1;
        ///веро€тнось выподени€ id пропорциональна его частоте
        int n=rand()%c; //RAND_MAX
        int sum = 0;
        for (const auto& _pair : dic)
        {
            int sum1 = sum + _pair.second;
            if (in_range(n, sum, sum1))
                return _pair.first;
            sum = sum1;
        }
        assert(false);//нет фоловера!
        //todo
        return -1;
    }
    id random_next(id _id)
    {
        return random_next(id2fol_dict[_id], id2fol_count[_id]);
    }
    //генераци€:
    vector<id> generate(id start, int max_size=10000)
    {
        id cur = start;
        vector<id> g;
        if (cur == -1)
            return g;

        g.push_back(cur);
        for (int i = 0; i < max_size; i++)
        {
            cur = random_next(cur);
            if (cur == -1)
                break;
            g.push_back(cur);
        }
        return g;
    }
    string to_text(vector<id>& gen)
    {
        string t;
        for (id _id : gen)
            t += id2word[_id] + " ";
        return t;
    }
    id getid(const string& s)
    {
        auto search = word2id.find(s);
        id sid = -1;
        if (search != word2id.end())
            sid = search->second;
        return sid;
    }
    text_gen(const string& s)
    {
        init(s);
        prepare();
        id sid = getid("Non");
        vector<id> gen = generate(sid);
        auto result=to_text(gen);
    }
};

void test(const string& s)
{
    std::cout << s << std::endl;
    auto res = parser::parse(s);

    if(0)
    for (auto s : res)
        std::cout << "[" << s << ']' << std::endl;

    text_gen gen(s);
}

int main() {
    srand(0);
    test("Non-zero value if the character is a whitespace character, zero otherwise.");
    test("Ќенулевое значение, если символ €вл€етс€ пробелом, в противном случае Ч ноль.");
	return 0;
}
