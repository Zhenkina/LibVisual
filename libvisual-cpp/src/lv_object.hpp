// Libvisual-c++ - C++ bindings for Libvisual
//
// Copyright (C) 2005 Chong Kai Xiong <descender@phreaker.net>
//
// Author: Chong Kai Xiong <descender@phreaker.net>
//
// $Id: lv_object.hpp,v 1.8 2005-09-26 13:28:07 descender Exp $
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

#ifndef LVCPP_OBJECT_HPP
#define LVCPP_OBJECT_HPP

#include <libvisual/lv_object.h>

namespace Lv
{
  // Notes:
  // * Might be nice if we can allocate Object entirely on the
  //   stack.

  class Object
  {
  public:

      // need to make this exception safe
      Object ()
          : m_object (visual_object_new ())
      {}

      Object (VisObject *object)
          : m_object (object)
      {}

      ~Object ()
      {
          unref ();
      }

      inline void ref ()
      {
          visual_object_ref (m_object);
      }

      inline void unref ()
      {
          visual_object_unref (m_object);
      }

      inline void take_vis_object (VisObject *object)
      {
          unref ();
          m_object = object;
      }

      inline const VisObject& vis_object () const
      {
          return *m_object;
      }

      inline VisObject& vis_object ()
      {
          return *m_object;
      }

  private:

      VisObject *m_object;

      Object (const Object& object);
      const Object& operator = (const Object& other);
  };


  template <class Object>
  class RefPtr
  {
  public:

      explicit RefPtr (Object *object = 0)
          : m_object (object)
      {}

      RefPtr (const RefPtr& other)
          : m_object (other.m_object)
      {
          if (m_object)
              m_object->ref ();
      }

      ~RefPtr ()
      {
          if (m_object)
              m_object->unref ();
      }

      const RefPtr& operator = (const RefPtr& other)
      {
          if (m_object)
              m_object->unref ();

          m_object = other.m_object;

          if (m_object)
              m_object->ref ();

          return *this;
      }

      const Object *operator -> () const
      {
          return m_object;
      }

      Object *operator -> ()
      {
          return m_object;
      }

      const Object& operator * () const
      {
          return *m_object;
      }

      Object& operator * ()
      {
          return m_object;
      }

  private:

      Object *m_object;
  };

} // namespace Lv

#endif // #ifndef LVCPP_OBJECT_HPP
