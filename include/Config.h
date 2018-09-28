//===============================================================
//  D O P A M I N E     >(@ > @)<
//  Experimental Neural Network with Global Reward Reinforcement
//  See LICENSE file in top directory
//===============================================================

#ifndef DOPAMINE_CONFIG_H
#define DOPAMINE_CONFIG_H

#include <string>
#include <map>
#include <cmath>

class Config
{
public:
   //! Singleton implementation.
   static Config& instance();

   /** Initializes default configmap */
   Config();

   /** Initializes configmap from JSON file provided*/
   Config(const std::string& configFilename);

   /** Fetch named parameter as a string value. Returns empty string if not found. */
   std::string asString(const std::string paramKey);

   /** Fetch named parameter as a float value. Returns NaN if not found or not convertible. */
   double asFloat(const std::string paramKey);

   /** Fetch named parameter as an int value. Returns defaultVal if not found or not convertible. */
   int asInt(const std::string paramKey, int defaultVal=-99999);

   /** Fetch named parameter as a boolean value. Returns defaultVal if not found or not convertible. */
   bool asBoolean(const std::string paramKey, bool defaultVal=false);

private:
   void initDefaults();

   std::map<std::string, std::string> m_configMap;
};

#endif //DOPAMINE_CONFIG_H

