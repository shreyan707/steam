#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to read the contents of a file into a vector of strings
vector<string> readFile(const string& filename) {
  vector<string> lines;
  ifstream infile(filename);

  if (infile.is_open()) {
    string line;
    while (getline(infile, line)) {
      lines.push_back(line);
    }
    infile.close();
  } else {
    cerr << "Error opening file: " << filename << endl;
  }

  return lines;
}

// Function to write the contents of a vector of strings to a file
void writeFile(const string& filename, const vector<string>& lines) {
  ofstream outfile(filename);

  if (outfile.is_open()) {
    for (const string& line : lines) {
      outfile << line << endl;
    }
    outfile.close();
  } else {
    cerr << "Error opening file: " << filename << endl;
  }
}

int main() {
  string filename = "test.txt";  // Replace with your actual filename
  string targetLine = "gaminizer";  // Line where you want to insert text
  int position = 5;  // Position (character index) to insert (starting from 1)
  string newText = " (updated)";  // Text to insert

  // Read the file contents into a vector
  vector<string> lines = readFile(filename);

  // Check if the target line exists
  bool found = false;
  for (size_t i = 0; i < lines.size(); ++i) {
    if (lines[i].find(targetLine) != string::npos) {
      found = true;
      lines[i].insert(position - 1, newText);  // Insert at position-1 (zero-based index)
      break;
    }
  }

  if (!found) {
    cerr << "Target line not found in the file." << endl;
  } else {
    // Write the modified content back to the file
    writeFile(filename, lines);
    cout << "Text inserted successfully!" << endl;
  }

  return 0;
}
