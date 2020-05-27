#include "../src/substrate-methods.h"

// keypair used for testing (native in Substrate)
static struct test_keypair {
    uint8_t public_key[ADDRESS_LEN];
    uint8_t private_key[ADDRESS_LEN];
} Alice;
    
void static inline generate_Alices_test_keypair(SubstrateKeypair *keypair) {

    const uint8_t privkey_sender[ADDRESS_LEN] = {0xab, 0xf8, 0xe5, 0xbd, 0xbe, 0x30, 0xc6, 0x56, 0x56, 0xc0, 0xa3, 0xcb, 0xd1, 0x81, 0xff, 0x8a, 0x56, 0x29, 0x4a, 0x69, 0xdf, 0xed, 0xd2, 0x79, 0x82, 0xaa, 0xce, 0x4a, 0x76, 0x90, 0x91, 0x15};
    const uint8_t pubkey_sender[ADDRESS_LEN] = {0x88, 0xdc, 0x34, 0x17, 0xd5, 0x05, 0x8e, 0xc4, 0xb4, 0x50, 0x3e, 0x0c, 0x12, 0xea, 0x1a, 0x0a, 0x89, 0xbe, 0x20, 0x0f, 0xe9, 0x89, 0x22, 0x42, 0x3d, 0x43, 0x34, 0x01, 0x4f, 0xa6, 0xb0, 0xee};

    SUBSTRATE_MEMCPY(Alice.public_key, pubkey_sender, ADDRESS_LEN);
    SUBSTRATE_MEMCPY(Alice.private_key, privkey_sender, ADDRESS_LEN);

    SUBSTRATE_MEMCPY(&(keypair->sk[0]), privkey_sender, ADDRESS_LEN);
    SUBSTRATE_MEMCPY(&(keypair->sk[ADDRESS_LEN]), pubkey_sender, ADDRESS_LEN);
}