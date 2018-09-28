//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#include <Config.h>
#include <json/json.h>
#include <exception>
#include <fstream>

using namespace std;

Config &Config::instance()
{
   static Config singleton;
   return singleton;
}

Config::Config()
{
   initDefaults();
}

Config::Config(const std::string &configFilename)
{
   initDefaults();

   // Load the specified configuration. This will override the common defaults:
   ifstream configFile (configFilename);
   if (configFile.fail())
      throw "Bad file open for config file.";

   Json::Value jsonRoot;
   configFile >> jsonRoot;

   Json::Value::Members members = jsonRoot.getMemberNames();
   for (auto &member : members)
      m_configMap[member] = jsonRoot[member].toStyledString();

   configFile.close();
}

std::string Config::asString(const std::string paramKey)
{
   auto iter = m_configMap.find(paramKey);
   if (iter == m_configMap.end())
      return "";

   return iter->second;
}

double Config::asFloat(const std::string paramKey)
{
   string strval (asString(paramKey));
   if (strval.empty())
      return NAN;

   return atof(strval.c_str());
}

int Config::asInt(const std::string paramKey, int defaultVal)
{
   string strval (asString(paramKey));
   if (strval.empty())
      return defaultVal;
   if (strval == "0")
      return 0;
   int rtnval = atoi(strval.c_str());
   if (rtnval)
      return rtnval;

   return defaultVal;
}

bool Config::asBoolean(const std::string paramKey, bool defaultVal)
{
   string strval (asString(paramKey));
   if ((strval == "true") || (strval == "yes") || (strval == "1"))
      return true;
   else if ((strval == "false") || (strval == "no") || (strval == "0"))
      return false;

   return defaultVal;
}

void Config::initDefaults()
{
   m_configMap["agingRate"] = "0.01";
}
