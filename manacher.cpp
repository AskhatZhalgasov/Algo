class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      vector < int > d1(n, 0);
      int answer = 0;
      for (int i = 0, l = 0, r = 0;i < n;i++) {
        int k = (i <= r ? min(r - i, d1[l + r - i]) : 0);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
          k++;
        }
        d1[i] = --k;
        answer = max(answer, 2 * k + 1);
        if (i + k > r) {
          l = i - k, r = i + k;
        }
      }
      vector < int > d2(n, 0);
      for (int i = 0, l = 0, r = 0;i < n;i++) {
        int k = (i < r ? min(r - i, d2[l + r - i - 1]) : 0);
        while(i - k + 1 >= 0 && i + k < n && s[i - k + 1] == s[i + k]) {
          k++;
        }
        d2[i] = --k;
        answer = max(answer, 2 * k);
        if (i + k > r) {
          l = i - k + 1, r = i + k;
        }
      }
      string ret = "";
      if (answer % 2) {
        for (int i = 0;i < n;i++) {
          if (answer == 2 * d1[i] + 1) {
            ret = s.substr(i - d1[i], answer);
            break;
          }
        }
      } else {
        for (int i = 0;i < n;i++) {
          if (answer == 2 * d2[i]) {
            ret = s.substr(i - d2[i] + 1, answer);
          }
        }  
      }
      return ret;
    }
};