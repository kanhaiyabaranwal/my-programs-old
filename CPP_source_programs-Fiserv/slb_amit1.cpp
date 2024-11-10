#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<fstream>
#include<cstdlib>
#include<utility>
#define NUM_FIELDS 4
struct SplitLine {
  std::string fields[NUM_FIELDS];
};


typedef struct {
	std::string server;
	std::string version;
} serv_ver;

typedef std::multimap<std::string,serv_ver>::const_iterator mapIter;

int processData(std::vector<struct SplitLine> data) 
{
	std::multimap<std::string,serv_ver> mmap;
	std::map<std::string,std::string> smap;
	std::map<std::string,std::string>::iterator miter; 
	std::vector<struct SplitLine>::const_iterator iter=data.begin();
	serv_ver sv;
		for(;iter!=data.end();iter++)
         {
         	
           	for (int i=0; i<NUM_FIELDS; i++) 
           	{
           		if(i==3)
           		{
           			sv={iter->fields[0],iter->fields[3]};
           			mmap.insert(make_pair(iter->fields[2],sv));
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
    mapIter m_it;
    std::map<std::string,std::string>::const_iterator siter; 
    std::set<std::string> serverset;
    for (m_it = mmap.begin();  m_it != mmap.end();  )
    {
        std::string key = m_it->first;

        std::cout << std::endl;
        std::cout << "  key = '" << key << "'" << std::endl;

        //std::pair<mapIter, mapIter> keyRange = mmap.equal_range(theKey);
		int keycnt=mmap.count(key);
        // Iterate over all map elements with key == theKey
		int count=0;
        //for (s_it = keyRange.first;  s_it != keyRange.second;  ++s_it)
        for(int i=0;i<keycnt;i++,m_it++)
		{
           //cout << "    value = " << (*s_it).second << endl;
           siter=smap.find(m_it->first);
           if((m_it->second).version!=siter->second)
           {
           		serverset.insert((m_it->second).server);
            }
    	}
    }
    tcount=serverset.size();
    std::cout<<"server set="<<serverset.size()<<std::endl;    
    return tcount;
}


int main()
{
	std::ifstream in("input.txt");
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

