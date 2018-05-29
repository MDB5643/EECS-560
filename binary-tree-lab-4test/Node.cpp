/**
 * @file Node.cpp
 * @author Matt Bailey
 * @since 2016.03.01
 */

#include "Node.h"

Node::Node()
{

  m_next = nullptr;

}

void Node::setValue(int value)
{
  m_value = value;

}

int Node::getValue() const
{
  return m_value;

}

void Node::setNext(Node* prev)
{
  m_next = prev;

}

Node* Node::getNext() const
{
  return m_next;

}
