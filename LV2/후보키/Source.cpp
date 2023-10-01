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

    // �־��� ���� �ȿ��� ���� �� �ִ� ��� ������ �����
    BFS_SetKeys();

    // �Ը� ���� ���� �ͺ��� �����ؼ� ���� ū ������ �˻��ϵ�
    // �ĺ�Ű�� ���� ��� �ش� ������ ������ ������ 0���� �����Ѵ�
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

// ���� �켱 Ž���� �̿��Ͽ� ��� ������ Ű ������ �����.
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

// ���� �Ӽ� ���ڿ� �����Ͽ� ������ ���� �� ���ϼ� �˻� �� ����� ��ȯ
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

// �Ӽ� ��ȣ�� 2������ ��ȯ�ϴ� �Լ�
int ToBinaryKey(vector<int> keySet)
{
    int binaryKey = 0;
    for (int n : keySet)
        binaryKey += (1 << n);

    return binaryKey;
}

// �Է¹��� 2���� �Ӽ���ȣ�� �Է¹��� ��������� Ȯ���Ͽ� �����ϴ� �Լ�
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