#include "Depurador.hpp"

depurador::depurador()
{
}

wchar_t* depurador::getText(const locale loc, string name)
{
  wifstream txt(name, ios::binary);

  if(!txt.is_open())
  {
    cerr << "Não foi possível abrir o arquivo " << name << endl;
    exit(1);
  }


  txt.imbue(loc);

  
  txt.seekg(0, ios::end);

  streampos tamanho = txt.tellg();
      
  
  txt.seekg(0, ios::beg);

  wchar_t* buffer = new wchar_t[tamanho];

  txt.read(buffer, tamanho);
  
  txt.close();

  return buffer;
}

unordered_set<wstring> depurador::getStopWords(const locale loc)
{
  wstring word;
  unordered_set<wstring> stopwords;
  
  wifstream file("dataset/stopwords.txt");

  if(!file.is_open())
  {
    cerr << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }

  file.imbue(loc);

  while (file >> word)
  {
    stopwords.insert(word);
  }

  file.close();

  return stopwords;
  
}

void depurador::printHeap(vector<Item> heap)
{
  wstring_convert<std::codecvt_utf8<wchar_t>> converter;
  
  for (auto i = 0u; i < heap.size(); i++)
  {
    cout << "Palavra: " << converter.to_bytes(heap[i].getNome()) << " --- " << "Frequência: "<< heap[i].getFrequencia() << endl;
  }
}
