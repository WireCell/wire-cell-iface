#include "WireCellIface/SimpleTrace.h"

using namespace WireCell;

SimpleTrace::SimpleTrace(int chid, int tbin, const ChargeSequence& charge)
    : m_chid(chid), m_tbin(tbin), m_charge(charge)
{
}

int SimpleTrace::channel() const
{
    return m_chid;
}

int SimpleTrace::tbin() const
{
    return m_tbin;
}

const ITrace::ChargeSequence& SimpleTrace::charge() const
{
    return m_charge;
}
