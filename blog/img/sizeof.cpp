static const size_t FIELD_SIZE_MSGID = 15;

struct FEEDER_RECORD_HEADER
{
   char MessageID[FIELD_SIZE_MSGID];
   char MessageIndex[10];
};

// error C2143: syntax error : missing ')' before '.'
char MessageIndexBuffer[sizeof(FEEDER_RECORD_HEADER.MessageIndex) + 1];

// error C2070: '': illegal sizeof operand
char MessageIndexBuffer[sizeof(FEEDER_RECORD_HEADER::MessageIndex) + 1];