class Solution {
public:
bool isConsonant(char ch) 
{ 
    // To handle lower case 
    ch = toupper(ch); 
  
    return !(ch == 'A' || ch == 'E' ||  
            ch == 'I' || ch == 'O' ||  
            ch == 'U') && ch >= 65 && ch <= 90; 
} 
    bool isValid(string word) {
        bool size=false,digits=false,vowel=false,consonant=false;
        if(word.size()>=3) size=true;
        int cnt=0;
        if(size==false) return false;
        for(int i=0;i<word.size();i++){
            if(word[i]>='0'&&word[i]<='9'){
                digits=true;
                cnt++;
            }
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U'){
                vowel=true;
                cnt++;
            }
            if(isConsonant(word[i])==true){
                consonant=true;
                cnt++;
            }}
            
            if(cnt==word.size()&&vowel==true&&consonant==true) return true;
            else return false;



        
    }
};