/**
 * Helpers.h
 * Common functions that don't belong anywhere specific
 */

#ifndef HELPERS_H
#define HELPERS_H

/**
 * Split a string by delimiter and return index
 * Originally from https://stackoverflow.com/questions/9072320/split-string-into-string-array
 * 
 * @param data      The input string
 * @param separator The delimiter
 * @param index     Index of portion of string to return
 * @returns String  String containing data || blank
 */
String splitString(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

#endif