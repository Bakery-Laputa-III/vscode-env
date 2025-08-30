#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

bool cmp_by_y1(const vector<int>& light1, const vector<int>& light2) {
    return light1[2] < light2[2];
}

bool cmp_by_x1(const vector<int>& light1, const vector<int>& light2) {
    return light1[1] < light2[1];
}

bool in_line(const vector<int>& base_light, const vector<int>& light) {
    double radius = ((double)base_light[4] - (double)base_light[2]) / 2;
    return abs(base_light[2] - light[2]) <= radius;
}

int main() {
    /*输入处理*/
    int nums = 0;
    cin >> nums;
    vector<vector<int>> lights(nums, vector<int>(5));
    for (int i = 0; i < nums; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> lights[i][j];
        }
    }
    vector<int> order;

    /*首先将所有的灯按照y1排序*/
    sort(lights.begin(), lights.end(), cmp_by_y1);

    /*将同一行的放入同一vector, 并且按照x1排序*/
    vector<vector<int>> tmp;
    for (int i = 0; i < lights.size(); i++) {
        if (tmp.empty()) {
            tmp.push_back(lights[i]);
            continue;
        }
        
        if (in_line(tmp[0], lights[i])) {
            tmp.push_back(lights[i]);
        } else {
            // 对当前组按x1排序并添加到order
            sort(tmp.begin(), tmp.end(), cmp_by_x1);
            for (const auto& light : tmp) {
                order.push_back(light[0]);
            }
            tmp.clear();
            tmp.push_back(lights[i]);
        }
    }
    
    // 处理最后一组
    if (!tmp.empty()) {
        sort(tmp.begin(), tmp.end(), cmp_by_x1);
        for (const auto& light : tmp) {
            order.push_back(light[0]);
        }
    }
    
    for (const auto& i : order) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}