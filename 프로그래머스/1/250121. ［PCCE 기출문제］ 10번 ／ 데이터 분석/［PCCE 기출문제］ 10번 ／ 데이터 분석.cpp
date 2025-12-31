#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    vector<int> mydata;
    int sort_index = -1;
    Data(vector<int> &mydata, int sort_index) 
    { 
        setData(mydata); 
        this->sort_index = sort_index;
    }
    
    void setData(vector<int> &mydata)
    {
        this->mydata = mydata;
    }
    
    //정렬
    const bool operator < (Data & data ) const
    {
        return this->mydata[sort_index] < data.mydata[sort_index];
    }
};

//코드번호, 제조일, 최대수량, 현재수량
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    vector<Data> dataList;
    
    answer = vector<vector<int>>();
    dataList = vector<Data>();
    
    for(int i = 0; i < data.size(); i++)
    {
        int j, k = -1;
        if("code" == ext)
            j = 0;
        else if("date" == ext)
            j = 1;
        else if("maximum" == ext)
            j = 2;
        else
            j = 3;
        
        if("code" == sort_by)
            k = 0;
        else if("date" == sort_by)
            k = 1;
        else if("maximum" == sort_by)
            k = 2;
        else
            k = 3;
        
        //값 쿼리
        if(data[i][j] < val_ext)
        {
            dataList.push_back(Data(data[i], k));
        }
    }
    sort(dataList.begin(), dataList.end());
    
    for(int i = 0; i < dataList.size(); i++)
    {
        answer.push_back(dataList[i].mydata);
    }
    return answer;
}