/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the concrete encryption1 product class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-encryption1_product.h"
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

Encryption1Product::~Encryption1Product() {}

void Encryption1Product::encrypt(const string &filename) const
{
  int n;
  do
  {
    cout << "Enter encryption key (0 < N < 128): ";
    cin >> n;
  } while (n < 1 || n > 127);
  clearBuffer();

  // Read and encrypt file contents.
  ifstream file(filename);
  if (file.is_open())
  {
    vector<int> cipher;
    char c;
    while (file.get(c)) // Note: newline char will also be encrypted.
    {
      cipher.push_back(static_cast<int>(c) + n);
      cout << cipher.back() << ' ';
    }
    cout << endl;

    // Write cipher text back to file.
    ofstream file(filename);
    for (auto &i : cipher)
      file << i << ' ';
    file.close();
  }
  else cerr << "Failed to open and write to file" << endl;
}

void Encryption1Product::decrypt(const string &filename) const
{
  int n;
  do
  {
    cout << "Enter decryption key (0 < N < 128): ";
    cin >> n;
  } while (n < 1 || n > 127);
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
      for (int crypted_char; iss >> crypted_char;)
      {
        plain.push_back(static_cast<char>(crypted_char - n));
        cout << plain.back();
      }
    }

    // Write plain text back to file.
    ofstream file(filename);
    for (auto &c : plain)
      file << c;
    file.close();
  }
  else cerr << "Failed to open and write to file" << endl;
}
