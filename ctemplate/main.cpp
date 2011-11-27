#include <stdlib.h>
#include <string>
#include <iostream>
#include <sys/time.h>
#include <ctemplate/template.h>

int millitime() {
  struct timeval tim;
  gettimeofday(&tim, NULL);
  return (int)(tim.tv_sec*1000 + (tim.tv_usec/1000));
}

void test_simple() {
  ctemplate::TemplateDictionary dict("story");
  dict.SetValue("name", "Mustache.js");
  dict.SetValue("url", "http://github.com/janl/mustache.js");
  dict.SetValue("source", "git://github.com/janl/mustache.js.git");

  std::string output;
  ctemplate::ExpandTemplate("story.tpl", ctemplate::DO_NOT_STRIP, &dict, &output);
}

void test_loop() {
  ctemplate::TemplateDictionary* dict = new ctemplate::TemplateDictionary("comment");
  dict->SetValue("header", "My Post Comments");
  ctemplate::TemplateDictionary* sub_dict;
  sub_dict = dict->AddSectionDictionary("comments");
  sub_dict->SetValue("name", "Joe");
  sub_dict->SetValue("body", "Thanks for this post!");
  sub_dict = dict->AddSectionDictionary("comments");
  sub_dict->SetValue("name", "Sam");
  sub_dict->SetValue("body", "Thanks for this post!");
  sub_dict = dict->AddSectionDictionary("comments");
  sub_dict->SetValue("name", "Heater");
  sub_dict->SetValue("body", "Thanks for this post!");
  sub_dict = dict->AddSectionDictionary("comments");
  sub_dict->SetValue("name", "Kathy");
  sub_dict->SetValue("body", "Thanks for this post!");
  sub_dict = dict->AddSectionDictionary("comments");
  sub_dict->SetValue("name", "George");
  sub_dict->SetValue("body", "Thanks for this post!");

  std::string output;
  ctemplate::ExpandTemplate("comment.tpl", ctemplate::DO_NOT_STRIP, dict, &output);
}

int array_sum(int a[], int num_elements)
{
   int i, sum=0;
   for (i=0; i<num_elements; i++)
   {
         sum = sum + a[i];
   }
   return(sum);
}

int benchmark(int p_times, int p_runner_times, void (*func)()) {
  int times = p_times;
  int results[times];
  while(times != 0) {
    int runner_times = p_runner_times;
    int startTime = millitime();
    while(runner_times != 0) {
      func();
      runner_times--;
    }
    int endTime = millitime();
    times--;
    results[times] = endTime - startTime;
  }

  return array_sum(results, p_times) / p_times;
}

int main(int argc, char** argv) {
  int avg = benchmark(10, 5000, &test_simple);
  std::cout << "Simple Test: " << avg << std::endl;
  avg = benchmark(10, 5000, &test_loop);
  std::cout << "Loop Test: " << avg << std::endl;
  return 0;
}