/*
    AlmAudioSms.cpp
    Copyright (C) 2005 zg

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

#include "AlmAudioSms.hpp"
#include <avkon.hrh> //EAknAudioPrefNewSpecialMessage

CAlmAudioSms* CAlmAudioSms::NewL(CEikonEnv* anEnv,CSettings* aSettings)
{
  CAlmAudioSms* self=new(ELeave)CAlmAudioSms(anEnv);
  CleanupStack::PushL(self);
  self->ConstructL(aSettings);
  CleanupStack::Pop(self);
  return self;
}

CAlmAudioSms::CAlmAudioSms(CEikonEnv* anEnv): CAlmAudioBase(anEnv)
{
}

TInt CAlmAudioSms::Priority(void)
{
  return 90; //stolen from ncnlist.exe
}

TMdaPriorityPreference CAlmAudioSms::PriorityPreference(void)
{
  return (TMdaPriorityPreference)EAknAudioPrefNewSpecialMessage;
}
