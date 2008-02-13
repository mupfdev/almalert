/*
    btobexserver.hpp
    Copyright (C) 2008 zg

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef __BTOBEXSERVER_HPP__
#define __BTOBEXSERVER_HPP__

#include <obex.h>
#include <bteng.hpp>

class CBtListenActive: public CBase,public MObexServerNotify
{
  public:
    void ConstructL(void);
    static void NewLC(void);
    ~CBtListenActive();
  private:
    CBtListenActive();
    void StartBTObexServerL(void);
    void StopBTObexServerL(void);
    void ResetObjectL(void);
    void DeleteObject(void);
  private: //MObexServerNotify
    void ErrorIndication(TInt aError);
    void TransportUpIndication(void);
    void TransportDownIndication(void);
    TInt ObexConnectIndication(const TObexConnectInfo& aRemoteInfo,const TDesC8& aInfo);
    void ObexDisconnectIndication(const TDesC8& aInfo);
    CObexBufObject* PutRequestIndication(void);
    TInt PutPacketIndication(void);
    TInt PutCompleteIndication(void);
    CObexBufObject* GetRequestIndication(CObexBaseObject* aRequiredObject);
    TInt GetPacketIndication(void);
    TInt GetCompleteIndication(void);
    TInt SetPathIndication(const CObex::TSetPathInfo& aPathInfo,const TDesC8& aInfo);
    void AbortIndication(void);
  private:
    CObexServer* iObexServer;
    TSdpServRecordHandle iSdpServRecordHandle;
    CBTConnection* iBTConnection;
    CObexBufObject* iCurrObject;
    CBufFlat* iBuffer;
};

#endif
