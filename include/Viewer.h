/* -*- Mode: c++; tab-width: 2; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/* vim:set softtabstop=2 shiftwidth=2 tabstop=2 expandtab: */
#ifndef Viewer_H
#define Viewer_H

#include <cmath>

namespace osg {
  class Node;
}

class Viewer
{
  public:
    Viewer();
    ~Viewer(void);

    void operator()(std::vector<osg::Node*> vecViewData);
};

#endif // Viewer_H
