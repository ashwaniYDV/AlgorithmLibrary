// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example:
txt = forxxorfxdofr
pat = for
Output: 
3

Example:
txt = catca
pat = cat
Output: 
3
*/



// Method 1

class Solution {
public:
    int search(string pat, string str) {
        vector<int> freqPat(26), freqStr(26);
        for (char x : pat) freqPat[x - 'a']++;

        int res = 0;
        for (int i = 0; i < pat.size(); i++) {
            freqStr[str[i] - 'a']++;
        }

        if (freqStr == freqPat) res++;

        for (int i = pat.size(); i < str.size(); i++) {
            freqStr[str[i - pat.size()] - 'a']--;
            freqStr[str[i] - 'a']++;

            if (freqStr == freqPat) res++;
        }

        return res;
    }
};











// Method 2.1
class Solution {
public:
    int search(string pat, string str) {
        // code here
        vector<int> freqPat(26), freqStr(26);
        for (char x : pat) freqPat[x - 'a']++;

        int l = 0, res = 0;
        for (int r = 0; r < str.size(); r++) {
            freqStr[str[r] - 'a']++;
            while (freqStr[str[r] - 'a'] > freqPat[str[r] - 'a']) {
                freqStr[str[l] - 'a']--;
                l++;
            }

            if (freqStr == freqPat) res++;
        }

        return res;
    }
};




// Method 2.2
class Solution{
public:
	int search(string pat, string str) {
	    // code here
	    vector<int> freqPat(26), freqStr(26);
	    for(char x: pat) freqPat[x - 'a']++;
	    
	    int l = 0, res = 0;
	    for(int r = 0; r < str.size(); r++) {
	        freqStr[str[r] - 'a']++;
	        while(freqStr[str[l] - 'a'] > freqPat[str[l] - 'a']) {
	            freqStr[str[l] - 'a']--;
	            l++;
	        }
	        
	        if(freqStr == freqPat) res++;
	    }
	    
	    return res;
	}
};
