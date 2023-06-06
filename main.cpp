#include <iostream>
#include <vector>
#include <algorithm>

#define vs vector<string>
#define aes acgtn[exp].size()
#define ae acgtn[exp]
#define ai arr[i]
#define acgtni acgtn[i]

using namespace std;

int index;
bool check=true;
vs answer(3,"");
vector<vs> acgtn(6);

void func(vs arr) {
    int ci;
    vector<vs> acgtn_output(6); // 공백:0, a:1, c:2, g:3, n:4, t:5

    for (int i = 0; i < arr.size(); i++) {
        if(ai.size() > index)
            switch (ai[index]) {
                case 'a' :
                    ci = 1;
                    break;
                case 'c' :
                    ci = 2;
                    break;
                case 'g' :
                    ci = 3;
                    break;
                case 'n' :
                    ci = 4;
                    break;
                case 't' :
                    ci = 5;
                    break;
                default :
                    break;
            }
        else
            ci = 0;

        acgtn_output[ci].push_back(ai);
    }

    for(int i=0; i<6;i++)
        acgtni = acgtn_output[i];             // 다음 acgtn

    index++;
}

string radix(vector<string> arr, int k) {
    index=0;
    int exp;
    bool two=false;
    func(arr);

    while(true) {
        int tmp = 0;
        for (exp = 0; exp < 6; exp++) {
            tmp += aes;                     // aes : acgtn[exp].size()
            if(k <= tmp)
                break;
        }
        tmp -= aes;

        if(check && aes == 2){              // acgtn 2개인지 체크
                check = false;
                two = true;
        }
        if(aes == 1)                        // 최종 1개 나오면 탈출
            break;

        func(ae);
        k -= tmp;
    }

    if(two)                                 // acgtn 2개일때 answer에 2개 넣어주기
        for(int i=0;i<6;i++) {
            if (i == exp) continue;
            if (acgtni.size() != 0) {
                int tmp_index = i < exp ? 0 : 2;
                answer[tmp_index] = acgtni[0];
                break;
            }
        }
    check = false;
    return ae[0];
}

int main() {
    int k; cin >> k;
    vs Reads;

    string str;

    while (cin >> str)
        Reads.push_back(str);

    answer[1] = radix(Reads, k);

    int tmp_index = answer[0] != "" ? 2 : answer[2] != "" ? 0 : -1;

    if(tmp_index != -1)
        answer[tmp_index] = radix(Reads, k+tmp_index-1);
    else {
        answer[0] = radix(Reads, k - 1);
        answer[2] = radix(Reads, k + 1);
    }

    for(int i=0;i<3;i++)        // READS에서 answer index 찾기
        cout << find(Reads.begin(),Reads.end(),answer[i]) - Reads.begin() + 1 << "\n";

    return 0;
}