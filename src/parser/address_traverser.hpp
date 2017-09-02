//
//  address_traverser.hpp
//  blocksci
//
//  Created by Harry Kalodner on 7/29/17.
//
//

#ifndef address_traverser_hpp
#define address_traverser_hpp

namespace blocksci {
    struct OutputPointer;
    struct AddressPointer;
    struct Transaction;
    class ScriptAccess;
    class ScriptFirstSeenAccess;
    class DataAccess;
}

#include <cstdint>
#include <stdio.h>

class AddressTraverser {
    
    void processP2SHAddress(const blocksci::ScriptAccess &access, const blocksci::AddressPointer &pointer, uint32_t txNum, uint32_t p2shNum);
    
    virtual void sawAddress(const blocksci::AddressPointer &pointer, uint32_t txNum) = 0;
    
    virtual void linkP2SHAddress(const blocksci::AddressPointer &pointer, uint32_t txNum, uint32_t p2shNum) = 0;
    
public:
    void processTx(const blocksci::DataAccess &access, const blocksci::Transaction &tx);
};

#endif /* address_traverser_hpp */