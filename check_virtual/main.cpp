/*демонстрация того, что:
Виртульная функция HostEntityGiPathMaker::attachReactor неправильно определена,
Она никогда не вызовется через базовый клас EntityGiPathMaker.
*/

#include <iostream>
using namespace std;

#define HOST_VECTORIZER_UTILS_API
struct OdGsSelectionReactor{};
struct HostGsSelectionReactor : public OdGsSelectionReactor{};
struct OdGiViewport{};


struct EntityGiPathMaker
{
	HOST_VECTORIZER_UTILS_API virtual void attachReactor(OdGsSelectionReactor * pReactor, const OdGiViewport * viewInfo)
	{
		cout << "\tEntityGiPathMaker::attachReactor\n";
	}
};

struct OdEntityGiPathMaker : public EntityGiPathMaker
{
	HOST_VECTORIZER_UTILS_API virtual void attachReactor(OdGsSelectionReactor * pReactor, const OdGiViewport * viewInfo)
	{
		cout << "\tOdEntityGiPathMaker::attachReactor\n";
	}
};

class HostEntityGiPathMaker : public EntityGiPathMaker
{
	HOST_VECTORIZER_UTILS_API virtual void attachReactor(HostGsSelectionReactor * pReactor, const OdGiViewport * viewInfo)
	{
		cout << "\tHostEntityGiPathMaker::attachReactor\n";
	}
};

int main() { 
	OdGsSelectionReactor rOdGsSelectionReactor;
	HostGsSelectionReactor rHostGsSelectionReactor;
	OdGiViewport rOdGiViewport;
	
	EntityGiPathMaker* base=new OdEntityGiPathMaker();
	cout << "from OdEntityGiPathMaker(rOdGsSelectionReactor,...):\n";
	base->attachReactor(&rOdGsSelectionReactor, &rOdGiViewport);
	cout << "from OdEntityGiPathMaker(rHostGsSelectionReactor,...):\n";
	base->attachReactor(&rHostGsSelectionReactor, &rOdGiViewport);
	delete base;

	base=new HostEntityGiPathMaker();
	cout << "from HostEntityGiPathMaker(rOdGsSelectionReactor,...):\n";
	base->attachReactor(&rOdGsSelectionReactor, &rOdGiViewport);
	cout << "from HostEntityGiPathMaker(rHostGsSelectionReactor,...):\n";
	base->attachReactor(&rHostGsSelectionReactor, &rOdGiViewport);

	return 0; 
}
