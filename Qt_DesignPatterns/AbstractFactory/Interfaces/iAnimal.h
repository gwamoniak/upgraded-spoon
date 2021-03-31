#ifndef IANIMAL_H
#define IANIMAL_H

class iAnimal{
public:
  virtual void eat() = 0;
  virtual void sleep() = 0;
  virtual void move() = 0;
   virtual ~iAnimal() {};

};

#endif // IANIMAL_H
