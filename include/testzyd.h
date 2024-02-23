#include<istream>
#include<string>
#include<map>

namespace Zyd
{
    class zyd{
        public: 
            std::map<std::string,int>theMap={
                {"0",0},
                {"1",1},
                {"2",2},
                {"3",3},
                {"4",4},
                {"5",5}
            };

            int getString(std::string msg);
            int funcMap(int index);
    };
} // namespace zyd
