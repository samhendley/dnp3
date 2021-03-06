// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
//  
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
// 
#include "AsyncLinkLayerTest.h"

namespace apl { namespace dnp {

	AsyncLinkLayerTest::AsyncLinkLayerTest(LinkConfig arCfg, FilterLevel aLevel, bool aImmediate) :
	LogTester(aImmediate),
	mts(),
	upper(mLog.GetLogger(aLevel, "MockUpperLayer")),
	link(mLog.GetLogger(aLevel, "LinkLayer"), &mts, arCfg),	
	mNumSend(0)
	{
		link.SetUpperLayer(&upper);
		link.SetRouter(this);	
	}

	void AsyncLinkLayerTest::Transmit(const LinkFrame& arFrame)
	{
		mLastSend = arFrame;
		++mNumSend;
	}

	LinkConfig AsyncLinkLayerTest::DefaultConfig()
	{
		LinkConfig cfg(true, false);
		return cfg;
	}

}}

