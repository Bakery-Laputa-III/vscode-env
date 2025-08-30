#include <iostream>
#define RUN 1

#include <cstddef>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*TODO：处理输入*/
// string -> vevtor<char>
vector<char> read(string input) {
    vector<char> ans;
    stringstream ss(input);
    string token;
    while (getline(ss, token, '#')) {
        ans.push_back(stoi(token));
    }
    return ans;
}

/*TODO: 合理检测*/
// vector<char>元素合理：长度合理
bool illegal(const vector<char>& nums) {
    char size = nums.size();
    if (size != 4) return true;
    if (nums[0] < 1 || nums[0] > 128) return true;
    for (char i = 1; i < 4; i++) {
        if (nums[i] < 0 || nums[i] > 255) return true;
    }
    return false;
}

/*TODO: 将char转化为二位十六进制*/
// vector<char> -> vector<string>
vector<string> tohex(const vector<char>& nums) {
    vector<string> ans;
    stringstream ss;
    for (const auto& num : nums) {
        ss.str(""); ss.clear();
        ss << hex << setw(2) << setfill('0') << static_cast<int>(num);
        ans.push_back(ss.str());
    }
    return ans;
}

/*TODO：将vector<string> -> string*/
string combine(const vector<string>& ss) {
    string ans;
    for (const auto& s : ss) {
        ans += s;
    }
    return ans;
}

/*TODO: string: 16hex -> char*/
int toint(const string& s) {
    return stoi(s, nullptr, 16);
}

// 优化： 省略转成16hex的步骤， 直接按照字符相加
#if RUN
int main() {
    // 输入
    string input;
    getline(cin, input);

    // int化
    vector<char> nums = read(input);

    // illegal?
    if (illegal(nums) == true) {
        cout << "invaild IP" << endl;
    }

    // hex化
    vector<string> hexs = tohex(nums);

    // 整合
    string s = combine(hexs);

    // int
    int ans = toint(s);

    cout << ans << endl;

    return 0;
}
#endif
