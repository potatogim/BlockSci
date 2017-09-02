//
//  raw_input.hpp
//  blocksci_devel
//
//  Created by Harry Kalodner on 3/2/17.
//  Copyright © 2017 Harry Kalodner. All rights reserved.
//

#ifndef raw_input_hpp
#define raw_input_hpp

#include "inout.hpp"

#include <cstdint>
#include <string>
#include <stdio.h>


namespace blocksci {
    class ChainAccess;
    
    struct Input : public Inout {
        
        std::string toString() const;
        
        Transaction getSpentTx(const ChainAccess &access) const;
        
        #ifndef BLOCKSCI_WITHOUT_SINGLETON
        Transaction getSpentTx() const;
        #endif
    };
}

std::ostream &operator<<(std::ostream &os, blocksci::Input const &input);

#endif /* raw_input_hpp */