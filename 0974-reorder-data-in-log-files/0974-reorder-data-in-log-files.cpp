class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        auto isDigitLog = [](const string& log){
             int pos = log.find(' ');
            return isdigit(log[pos+1]);
        };

        vector<string> digilog, letterlog;

        for(auto & it: logs){
            if(isDigitLog(it)){
                digilog.push_back(it);
            }else{
                letterlog.push_back(it);
            }
        }


        sort(letterlog.begin(), letterlog.end(), [](const string& log1, const string& log2){
              int pos1 = log1.find(' ');
              int pos2 = log2.find(' ');

              string content1 = log1.substr(pos1+1);
              string content2 = log2.substr(pos2+1);
              string id1 = log1.substr(0, pos1);
              string id2 = log2.substr(0, pos2);


              if(content1 == content2){
                  return id1 < id2;
              }else{
                return content1 < content2;
              }
        });

        letterlog.insert(letterlog.end(), digilog.begin(), digilog.end());
        return letterlog;
    }
};