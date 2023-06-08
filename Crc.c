#include <stdio.h>
#include <stdint.h>

#define MAX_PACKET_DATA_LENGTH (50)

typedef struct data_packet_t {
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;
} data_packet_t;

uint16_t calculateCRC(data_packet_t* packet) {
    uint16_t crc = 0x0000;  // Initialize CRC value
    
    for (int i = 0; i < packet->data_length; i++) {
        crc ^= packet->data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    
    return crc;
}

int main() {
    
    data_packet_t originalPacket;
                  .id = 1;
                  .data_length = 6;
                  .data = {0x12, 0x34,0x56,0x78,0x9A,0xBC},
   
   
    originalPacket.crc = calculateCRC(&originalPacket); // Step 1: Calculate CRC

    // Simulating wireless transmission by assigning the packet to receivedPacket
    data_packet_t receivedPacket = originalPacket;  // Step 2: Transmit the data packet
    
    // Step 3: Receive the data packet
    
    uint16_t recalculatedCRC = calculateCRC(&receivedPacket);   // Step 4: Calculate CRC again on the received packet
 
    if (recalculatedCRC == receivedPacket.crc) {// Step 5: Compare CRC values with recieved packets
        printf("Data packet is not corrupted. Packet ID: %d\n", receivedPacket.id);
        // Process the received packet
    } else {
        printf("Data packet is corrupted. Packet ID: %d\n", receivedPacket.id);
        // Discard the packet
    }
    
    return 0;
}
