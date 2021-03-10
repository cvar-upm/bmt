/*!********************************************************************************
 * \brief     catalog definition file
 * \authors   Pablo Santamaria, Martin Molina
 * \copyright Copyright (c) 2020 Universidad Politecnica de Madrid
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <list>

// ROS
#include <ros/ros.h>
#include <yaml-cpp/yaml.h>

// Aerostack
#include "../include/task.h"
#include "../include/constraint.h"
#include "../include/behavior.h"
#include "../include/prettify.h"

class DefaultValue
{
public:
  std::string category;
  int timeout;
  double efficacy;
  std::string type;
  bool automatic_activation;
  bool default_value;
  DefaultValue(){};
  ~DefaultValue(){};
  
private:
};

class Catalog
{
public:
  bool testing;
  std::list<Behavior> behaviors;
  std::list<Task> initialTasks;
  std::list<Task*> tasks;
  std::list<Constraint*> constraints;
  std::list<DefaultValue> default_values;
  std::list<std::string> errors;
  Catalog(std::string path_file);
  Catalog();
  ~Catalog();
  void loadValues();

  //DEBUG
  void printDebugInfo();
  void printValues();
  void printConstraints();
  void printInitialDomain();
  void printCandidateBehaviors();
  void discardInactiveNodes();
  void deleteInactiveTasks();
  void loadConstraints();
  void ordenateTasks();
  bool checkCatalog();
  
private:
  Prettify prettify;
  YAML::Node yaml_node;
};


#endif