/* 
 * Copyright (c) 2005-2011, Guillaume Gimenez <guillaume@blackmilk.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of G.Gimenez nor the names of its contributors may
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL G.GIMENEZ BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *     * Guillaume Gimenez <guillaume@blackmilk.fr>
 *
 */
#ifndef __REQUESTDISPATCHER_H__
#define __REQUESTDISPATCHER_H__

#include "Object.H"

namespace raii {
  class ServletContext;
  class HttpServletRequest;
  class HttpServletResponse;

  class RequestDispatcher : public Object {
  public:
    RequestDispatcher(const String& _contextPath,
					 const String& _uri);
    /*! forward the current process to this configured RequestDispatcher
     * \param request is the current request, not a newly created
     * \param response is the current response, not a newly created
     * \return never return, RequestOK("RequestDispatcher::forward") is thrown and should be catched by mod_raii
     */
    void forward(HttpServletRequest& request, HttpServletResponse& response);

    /*! include in the current process the execution of this configured RequestDispatcher
     * \param request is the current request, not a newly created
     * \param response is the current response, not a newly created
     */
    void include(HttpServletRequest& request, HttpServletResponse& response);

    virtual String dump(const String& str) const;

  private:
    void service(HttpServletRequest& request,
                 HttpServletResponse& response);
    String contextPath;
    String uri;
  };

}

#endif /* __REQUESTDISPATCHER_H__ */
