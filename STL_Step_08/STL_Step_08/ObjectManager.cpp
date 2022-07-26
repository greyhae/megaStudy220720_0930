#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;


ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::Initialize()
{
	EnableList = ObjectPool::GetInstance->GetEanblList();
}

void ObjectManager::DisableFormEnable()
{
	// ** null이 있는 경우는 try ~ catch 문 사용
	// ** 지금은 null이 없다고 가장

	auto iter = EnableList->find("Player");
	ErrorMessage(__LINE__);

	// 생성
	Object* pObj = ObjectPool::GetInstance()->Insert("Player");

	if (pObj == nullptr)
	{

		// ** Error Mesage
		return;
	}

	if (iter == EnableList->end())
	{
		list<Object*> temp;
		for (int i = 0; i < 5; ++i)
		{
			temp.push_back(ProtoObject->Clone());
			EnableList.insert(make_pair(pObj->GetKey(), temp));
		}

	}
	else
		iter->second.push_back(pObj);
	
}

void ObjectManager::EnableFormDisable()
{
	// ** 테스트 코드
	//auto pObj = EnableList
	ObjectPool::GetInstance()->Erase(pObj);
}

void ObjectManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		cout << " [EnableList : " << iter->first << "]" << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}

	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		cout << " [EnableList : " << iter->first << "]" << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
