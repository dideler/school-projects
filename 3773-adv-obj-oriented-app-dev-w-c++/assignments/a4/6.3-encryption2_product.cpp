/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the Encryption2Product concrete class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-encryption2_product.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;

Encryption2Product::~Encryption2Product() {}

void Encryption2Product::encrypt(const string &filename) const
{
  cout << "Enter encryption keyword: ";
  string keyword;
  cin >> keyword;
  clearBuffer();

  // Read and encrypt file contents.
  ifstream file(filename);
  if (file.is_open())
  {
    vector<int> cipher;
    string line;
    while (getline(file, line))
    {
      for (decltype(line.length()) i = 0; i < line.length();)
      {
        for (decltype(line.length()) j = 0; j < keyword.length();)
        {
          cipher.push_back(int(line[i++]) + int(keyword[j++]));
          cout << cipher.back() << ' ';
        }
      }
      cout << endl;
    }

    // Write cipher text back to file.
    ofstream file(filename);
    for (auto &i : cipher)
      file << i << ' ';
    file.close();
  }
  else cerr << "Failed to open and write to file" << endl;
}

void Encryption2Product::decrypt(const string &filename) const
{
  cout << "Enter decryption keyword: "; // Note: uses a single keyword.
  string keyword;
  cin >> keyword;
  clearBuffer();

  // Read and decrypt file contents.
  ifstream file(filename);
  if (file.is_open())
  {
    vector<char> plain;
    string line;
    while (getline(file, line))
    {
      istringstream iss(line);
      for (int crypted_char, i = 0; iss >> crypted_char; ++i)
      {
        int ascii_code = keyword[i % keyword.length()];
        plain.push_back(char(crypted_char - ascii_code));
        cout << plain.back();
      }
    }
    cout << endl;

    // Write plain text back to file.
    ofstream file(filename);
    for (auto &c : plain)
      file << c;
    file.close();
  }
  else cerr << "Failed to open and write to file" << endl;
}
