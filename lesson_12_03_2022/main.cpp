
#include <iostream>
#include <vector>

using namespace std;


void move_pointer (vector<int> values, int &index) {
    int prev = values[index];
    while(index < values.size() && (values[index] == prev || values[index] == values[index + 1])) index++;
}

int main(int argc, const char * argv[]) {

    vector<int> values1 = {0, 1, 2, 2, 2, 60, 70};
    vector<int> values2 = {0, 1, 3, 3, 50, 80};
    vector<int> unique_values;
    
    sort(values1.begin(), values1.end());
    sort(values2.begin(), values2.end());
    
    int index1 = 0;
    int index2 = 0;
    
    
    while(index1 < values1.size() || index2 < values2.size()) {
        
        if(values1[index1] == values2[index2]) {
            move_pointer(values1, index1);
            move_pointer(values2, index2);
        } else if((values1[index1] < values2[index2] || index2 == values2.size())&& index1 < values1.size()) {
            unique_values.push_back(values1[index1]);
            move_pointer(values1, index1);
        } else if((values2[index2] < values1[index1] || index1 == values1.size()) && index2 < values2.size()){
            unique_values.push_back(values2[index2]);
            move_pointer(values2, index2);
        }
    }
    
    for(auto value : unique_values) cout << value << " ";
    cout << endl;
    
    
    return 0;
}
