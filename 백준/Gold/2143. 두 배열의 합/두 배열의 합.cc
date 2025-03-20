#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T = 0;
    std::cin >> T;
    
    int n = 0;
    std::cin >> n;
    int n_array[n]={};
    for(int i = 0; i < n; i++){
        std::cin >> n_array[i];
    }
    
    int m = 0;
    std::cin >> m;
    int m_array[m]={};
    for(int i = 0; i < m; i++){
        std::cin >> m_array[i];
    } 
    
    std::vector<int> n_sums, m_sums;
    for(int i = 0; i < n; i++){
        int sum = n_array[i];
        n_sums.push_back(sum);
        for(int j = i+1; j < n; j++){
            sum += n_array[j];
            n_sums.push_back(sum);
        }
    }
    
    for(int i = 0; i < m; i++){
        int sum = m_array[i];
        m_sums.push_back(sum);
        for(int j = i+1; j < m; j++){
            sum += m_array[j];
            m_sums.push_back(sum);
        }
    }
    
    std::sort(m_sums.begin(), m_sums.end());
    
    long long result = 0;
    for(int ns : n_sums){
        result += (std::upper_bound(m_sums.begin(), m_sums.end(), T-ns) - m_sums.begin())
            - (std::lower_bound(m_sums.begin(), m_sums.end(), T-ns) - m_sums.begin());
    }
    
    std::cout << result << "\n";
    
    
    return 0;
}