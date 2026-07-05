#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

    // Next Smaller Index
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                nsi[i] = n;
            else
                nsi[i] = st.top();

            st.push(i);
        }

        return nsi;
    }

    // Previous Smaller Index
    vector<int> previousSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> psi(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                psi[i] = -1;
            else
                psi[i] = st.top();

            st.push(i);
        }

        return psi;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> nsi = nextSmaller(heights);
        vector<int> psi = previousSmaller(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int width = nsi[i] - psi[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
    int main(){
        
        return 0;
    }
