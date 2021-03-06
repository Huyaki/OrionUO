// MIT License

#pragma once

#include "../Wisp/WispGlobal.h"
#include "aes.h"
#include "md5.h"

#define CRYPT_AUTO_VALUE 0x80

#define CRYPT_GAMEKEY_LENGTH 6
#define CRYPT_GAMEKEY_COUNT 25

#define CRYPT_GAMESEED_LENGTH 8
#define CRYPT_GAMESEED_COUNT 25

#define CRYPT_GAMETABLE_START 1
#define CRYPT_GAMETABLE_STEP 3
#define CRYPT_GAMETABLE_MODULO 11
#define CRYPT_GAMETABLE_TRIGGER 21036

class CBlowfishCrypt
{
private:
    static bool m_tables_ready;

    unsigned char m_seed[CRYPT_GAMESEED_LENGTH];
    int m_table_index;
    int m_block_pos;
    int m_stream_pos;

    void InitTables();
    void RawEncrypt(uint32_t *values, int table);

public:
    CBlowfishCrypt() {}
    ~CBlowfishCrypt() {}

    void Encrypt(uint8_t *in, uint8_t *out, int len);
    void Init();
};

class CTwofishCrypt
{
private:
    unsigned long m_IP;
    int m_pos;
    keyInstance ki;
    cipherInstance ci;
    uint32_t dwIndex;
    unsigned char m_subData3[256];
    MD5Crypt *m_md5;
    bool m_use_md5;
    unsigned char sm_bData[16];

public:
    CTwofishCrypt() {}
    ~CTwofishCrypt() {}

    void Init(uint8_t seed[4]);
    void Init_MD5();

    void Encrypt(const uint8_t *in, uint8_t *out, int size);
    void Decrypt(const uint8_t *in, uint8_t *out, int size);
};

extern CBlowfishCrypt g_BlowfishCrypt;
extern CTwofishCrypt g_TwofishCrypt;
