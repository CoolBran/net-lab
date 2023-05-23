#include "stream_reassembler.hh"

// Dummy implementation of a stream reassembler.

// For Lab 1, please replace with a real implementation that passes the
// automated checks run by `make check_lab1`.

// You will need to add private members to the class declaration in `stream_reassembler.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

StreamReassembler::StreamReassembler(const size_t capacity) : _output(capacity), _capacity(capacity) { _buffer.resize(capacity);}

//! \details This function accepts a substring (aka a segment) of bytes,
//! possibly out-of-order, from the logical stream, and assembles any newly
//! contiguous substrings and writes them into the output stream in order.

//--------------------------------------------------------
long StreamReassembler::merg_block(block_node& elm1, block_node& elm2) {
    block_node x,y;
    if(elm1.begin > elm2.begin) {
        x = elm2;
        y = elm1;
    }else{
        x = elm1;
        y = elm2;
    }
    if(x.begin + x.length < y.begin) {
        return -1; // without override part
    }else if(x.begin + x.length >= y.begin + y.length) {
        elm1 = x;
        return y.length;
    }else {
        elm1.begin = x.begin;
        elm1.data = x.data + y.datra.substr(x.begin + x.length - y.begin);
        elm1.length = elm1.data.length();
        return x.begin + x.length - y.begin;
    }
}

//--------------------------------------------------------
void StreamReassembler::push_substring(const string &data, const size_t index, const bool eof) {
    


}

size_t StreamReassembler::unassembled_bytes() const { return _unassembled_byte; }

bool StreamReassembler::empty() const { return _unassembled_byte == 0; }


//--------------------------------------------------------
