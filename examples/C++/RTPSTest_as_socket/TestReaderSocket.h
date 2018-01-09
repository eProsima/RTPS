// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file TestReaderSocket.h
 *
 */

#ifndef TESTREADERSOCKET_H_
#define TESTREADERSOCKET_H_

#include "fastrtps/rtps/rtps_fwd.h"


#include "fastrtps/rtps/reader/ReaderListener.h"

class TestReaderSocket {
public:
	TestReaderSocket();
	virtual ~TestReaderSocket();
	RTPSParticipant* mp_participant;
	RTPSReader* mp_reader;
	ReaderHistory* mp_history;
	bool init(std::string ip,uint32_t port);
	void run();
	class MyListener:public ReaderListener
	{
	public:
		MyListener():m_received(0){};
		~MyListener(){};
		void onNewCacheChangeAdded(RTPSReader* reader,const CacheChange_t* const change);
		uint32_t m_received;
	}m_listener;

};

#endif /* TESTREADER_H_ */
