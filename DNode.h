#pragma once

class DNode {
  private:
      std::string data;
      DNode *next, *prev;
  public:
      DNode();
      DNode(std::string data);
      DNode(std::string data, DNode *next, DNode *prev);
      ~DNode();


      void setNext(DNode *next);
      void setPrev(DNode *prev);
      void setData(std::string data);

      DNode *getNext();
      DNode *getPrev();
      std::string getData();
};
