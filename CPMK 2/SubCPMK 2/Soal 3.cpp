#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2)
{
  // Konversi string menjadi lowercase dan hapus spasi
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());

  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

  // Sort kedua string
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  // Bandingkan string yang telah diurutkan
  for (int i = 0; i < s1.length(); i++)
  {
    if (s1[i] != s2[i])
    {
      return false; // Bukan anagram
    }
  }

  return true; // Merupakan anagram
}

int main()
{
  // Input dua string
  string str1, str2;
  cout << "Masukkan string pertama: ";
  getline(cin, str1);

  cout << "Masukkan string kedua: ";
  getline(cin, str2);

  // Periksa apakah string adalah anagram
  if (isAnagram(str1, str2))
  {
    cout << str1 << " dan " << str2 << " adalah anagram." << endl;
  }
  else
  {
    cout << str1 << " dan " << str2 << " bukan anagram." << endl;
  }

  return 0;
}