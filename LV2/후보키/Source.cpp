#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> rel;
vector<vector<int>> keySets;
vector<int> banList;
int attributeSize;
int tupleSize;

bool IsCandidate(int binaryAttribute);
void BFS_SetKeys();
int ToBinaryKey(vector<int> keySet);
void RemoveSets(int banNum, int size);

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    rel = relation;
    tupleSize = relation.size();
    attributeSize = relation[0].size();
    keySets.resize(attributeSize + 1);

    // 주어진 정보 안에서 만들 수 있는 모든 조합을 만든다
    BFS_SetKeys();

    // 규모가 가장 작은 것부터 시작해서 점점 큰 순으로 검사하되
    // 후보키가 나올 경우 해당 조합을 포함한 조합은 0으로 변경한다
    for (int setSize = 1; setSize <= attributeSize; setSize++)
    {
        for (int idx = 0; idx < keySets[setSize].size(); idx++)
        {
            if (keySets[setSize][idx] == 0) continue;
            if (IsCandidate(keySets[setSize][idx]) == false) continue;

            answer++;
        }
    }

    return answer;
}

// 넓이 우선 탐색을 이용하여 모든 조합의 키 조합을 만든다.
void BFS_SetKeys()
{
    for (int iter = 0; iter < attributeSize; iter++)
        keySets[1].push_back(1 << iter);

    for (int att = 2; att <= attributeSize; att++)
    {
        for (int s : keySets[att - 1])
        {
            for (int iter = 0; iter < attributeSize; iter++)
            {
                int tmpNum = 1 << iter;
                if (s & tmpNum) continue;
                tmpNum += s;
                keySets[att].push_back(tmpNum);
            }
        }
    }
}

// 들어온 속성 인자에 접근하여 조합을 만들어낸 후 유일성 검사 후 결과를 반환
bool IsCandidate(int binaryAttribute)
{
    vector<int> attributes;
    map<string, int> keys;

    // to decimal
    int orderNum = 0;
    while (binaryAttribute > 0)
    {
        if (binaryAttribute & 1)
        {
            attributes.push_back(orderNum);
        }
        orderNum++;
        binaryAttribute >>= 1;
    }

    for (int tuple = 0; tuple < tupleSize; tuple++)
    {
        string key = "";
        for (int attribute : attributes)
        {
            key += rel[tuple][attribute];
        }
        keys[key]++;
    }

    for (pair<string, int> key : keys)
    {
        if (key.second > 1) return false;
    }

    int banNum = ToBinaryKey(attributes);
    RemoveSets(banNum, attributes.size());

    return true;
}

// 속성 번호를 2진수로 변환하는 함수
int ToBinaryKey(vector<int> keySet)
{
    int binaryKey = 0;
    for (int n : keySet)
        binaryKey += (1 << n);

    return binaryKey;
}

// 입력받은 2진수 속성번호를 입력받은 사이즈부터 확인하여 제거하는 함수
void RemoveSets(int banNum, int size)
{
    for (int idx = size; idx < keySets.size(); idx++)
    {
        for (int& s : keySets[idx])
        {
            if ((s & banNum) == banNum) s = 0;
        }

    }
}