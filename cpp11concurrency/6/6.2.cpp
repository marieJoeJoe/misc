#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <string>          // std::mutex
#include <vector>          // std::mutex

#include <list>
#include <regex>

std::list<std::string> r_split(const std::string& str, const std::regex& delim) {
    const std::sregex_token_iterator begin { str.cbegin(), str.cend(), delim, -1 }, end;
    return { begin, end };
}

std::string m_params_cut="params/mh100/MH100-F7D34A97/cut";
std::string m_params_area_remove="params/mh100/MH100-F7D34A97/area/remove";
std::string m_params_area_list="params/mh100/MH100-F7D34A97/area/list";
std::string m_params_speed="params/mh100/MH100-F7D34A97/speed";
std::string m_control_device="control/mh100/MH100-F7D34A97/device";
std::string m_params_area_add="params/mh100/MH100-F7D34A97/area/add";
std::string m_update_check_progress="update/mh100/MH100-F7D34A97/progress";
std::string m_update_check_check="update/mh100/MH100-F7D34A97/check";
std::string m_status ="/status/mh100/MH100-F7D34A97/device";
std::string m_status_e ="/status/mh100/MH100-F7D34A97/";

std::string params_cut="params/mh100/cut";
std::string params_area_remove="params/mh100/area/remove";
std::string params_area_list="params/mh100/area/list";
std::string params_speed="params/mh100/speed";
std::string control_device="control/mh100/device";
std::string params_area_add="params/mh100/area/add";
std::string update_check_progress="update/mh100/progress";
std::string update_check_check="update/mh100/check";
std::string status ="/status/mh100/device";


std::vector<std::string> ss = {
  params_cut,
  params_area_remove,
  params_area_list,
  params_speed,
  control_device,
  params_area_add,
  update_check_progress,
  update_check_check,
  status,
};


std::vector<std::string> m_ss = {
  m_params_cut,
  m_params_area_remove,
  m_params_area_list,
  m_params_speed,
  m_control_device,
  m_params_area_add,
  m_update_check_progress,
  m_update_check_check,
  m_status,
  m_status_e,
};



void get_device_sn(std::string& sn){
    sn.clear();
    sn.assign("MH100-F7D34A97");
}

template <typename _STRING>
std::ostream& operator<<(std::ostream& os,
                    const std::vector<_STRING>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << '\n';
    }
    return os;
}

std::vector<std::string> split(std::string str, std::string pattern){
  std::string::size_type pos;
  std::vector<std::string> result;

  str += pattern;

  int size = str.size();

  for(int i = 0; i < size; i++){
    pos = str.find(pattern, i);
    if(pos < size){
        std::string s = str.substr(i, pos - i);
        result.push_back(s);
        i = pos + pattern.size() - 1;
    }
  }
  return result;
}


void mcu_to_mqtt_topic(std::string& mcu_topic)
{
  uint32_t slash_count = ('/'==mcu_topic[0])?3:2;
  std::string device_sn;
  get_device_sn(device_sn);
  device_sn += "/";
  auto iter = mcu_topic.begin();
  for ( ; slash_count; iter++){
    if ('/' == *iter) slash_count--;
  }
  mcu_topic.insert(iter,device_sn.begin(),device_sn.end());
}

void mqtt_to_mcu_topic(std::string& mqtt_topic){
  uint32_t slash_count = ('/'==mqtt_topic[0])?4:3;
  std::string device_sn;
  get_device_sn(device_sn);
  device_sn += "/";
  auto iter1 = mqtt_topic.begin();
  auto iter0 = mqtt_topic.begin();
  auto iter = mqtt_topic.begin();
  for (; slash_count; iter++)
  {
        if ('/' == *iter){
            slash_count--;
            if(1 == slash_count) iter1 = iter;
            if(0 == slash_count) iter0 = iter;
        }
  }
  mqtt_topic.erase(iter1+1,iter0+1);
}

int main (int argc, char* argv[]) {

  std::string device_sn;
  std::string s = status;
  std::string delimiter = "/";

/*
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
  }
  std::cout << s << std::endl;
*/
  //std::vector<std::string> result=split(s, delimiter);

  //std::cout<<result<<std::endl;

  std::cout << "mcu_to_mqtt:"<<'\n';
  
  for(auto e:ss){
      std::cout << e<<'\n';
      mcu_to_mqtt_topic(e);
      std::cout << e<<'\n';
  }


  std::cout << "mqtt_to_mcu:"<<'\n';

  for(auto e:m_ss){
      std::cout << e<<'\n';
      mqtt_to_mcu_topic(e);
      std::cout << e<<'\n';
  }

  return 0;
}

