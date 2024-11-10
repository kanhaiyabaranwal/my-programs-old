#include<iostream>
#include<fstream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include<utility>


using namespace std;
#define NUM_FIELDS 4
struct SplitLine {
  std::string fields[NUM_FIELDS];
};
typedef multimap<string,string>::iterator mapIter;
int processData(std::vector<struct SplitLine> data) {
	std::multimap<string,string> mmap;
	std::map<string,string> smap;
	std::map<string,string>::iterator miter; 
	std::vector<struct SplitLine>::const_iterator iter=data.begin();
         for(;iter!=data.end();iter++)
         {
         	
           	for (int i=0; i<NUM_FIELDS; i++) 
           	{
           		if(i==3)
           		{
           			mmap.insert(make_pair(iter->fields[2],iter->fields[3]));
           			miter=smap.find(iter->fields[2]);	//map iterator
           			if(miter==smap.end())
           				smap.insert(make_pair(iter->fields[2],iter->fields[3]));
           			else if(miter->second < iter->fields[3])
           			{
           					smap.erase(miter);
           					smap.insert(make_pair(iter->fields[2],iter->fields[3]));
           					
           			}
					
           		}
         	//cout<<"value="<<iter->fields[i]<<",";
         	//cout<<endl;
         	}
        }
        
        int tcount=0;
        
        
        mapIter m_it, s_it;
        
    std::map<string,string>::const_iterator siter; 
    for (m_it = mmap.begin();  m_it != mmap.end();  m_it = s_it)
    {
        string theKey = (*m_it).first;

        //cout << endl;
        //cout << "  key = '" << theKey << "'" << endl;

        pair<mapIter, mapIter> keyRange = mmap.equal_range(theKey);

        // Iterate over all map elements with key == theKey
		int count=0;
        for (s_it = keyRange.first;  s_it != keyRange.second;  ++s_it)
        {
           //cout << "    value = " << (*s_it).second << endl;
           siter=smap.find(s_it->first);
           if(s_it->second!=siter->second)
           	count++;
        }
        if(count>1)
        	tcount++;
        	
    }
        
        
          
    return tcount;
}


int main()
{
	ifstream in("input.txt");
	  std::vector<struct SplitLine> input_data;

  while (in) {
    struct SplitLine line;
    for (int i=0; i<NUM_FIELDS; i++) {
      if (i==NUM_FIELDS-1)
      {
      
        std::getline(in, line.fields[i]);
        //cout<<line.fields[i];
    	}
      else
      {
      
        std::getline(in, line.fields[i], ',');
        //cout<<line.fields[i];
    	//cout<<"line "<<i<<"="<<line.fields[i]<<"\t";
    	}
    }
    if (line.fields[0] != "")
    {
        input_data.push_back(line);
        //cout<<"line="<<line.fields[0]<<endl;
    }
    //cout<<"line="<<line.fields[0]<<endl;
  }
  
  
  std::ofstream out("output.txt");
  //cout << processData(input_data) << std::endl;
  out << processData(input_data) << std::endl;
  
  return 0;
}

