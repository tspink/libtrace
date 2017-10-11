/*
 * TraceManager.cpp
 *
 *  Created on: 8 Aug 2014
 *      Author: harry
 */

/*
#include "gensim/gensim_decode.h"
#include "gensim/gensim_processor.h"

#include "tracing/TraceTypes.h"
*/

#include "libtrace/TraceSink.h"
#include "libtrace/TraceSource.h"
#include "libtrace/ArchInterface.h"

#include <cstdint>
#include <cassert>
#include <errno.h>
#include <map>
#include <string>
#include <streambuf>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace libtrace;

TraceSource::TraceSource(uint32_t BufferSize)
	:
	Tracing_Packet_Count(0),
	packet_open(false),
	is_terminated(false),
	suppressed(false),
	sink_(nullptr),
	aggressive_flushing_(true)
{
	packet_buffer = (TraceRecord*)malloc(PacketBufferSize * sizeof(TraceRecord));
	packet_buffer_end = packet_buffer+PacketBufferSize;
	packet_buffer_pos = packet_buffer;
}

TraceSource::~TraceSource()
{
	assert(is_terminated);
}

void TraceSource::EmitPackets()
{
	sink_->SinkPackets(packet_buffer, packet_buffer_pos);
	packet_buffer_pos = packet_buffer;
}

void TraceSource::Terminate()
{
	is_terminated = true;
}



void TraceSource::Flush()
{
	EmitPackets();
	sink_->Flush();
}
