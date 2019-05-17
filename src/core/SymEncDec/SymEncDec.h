#ifndef SYM_ENC_DEC_H
#define SYM_ENC_DEC_H


#include <DYNAMIC_LIBRARY_API.hpp>
#ifdef EXPORT_SymEncDec
#    define SymEncDec_API EXPORT_DYNAMIC_LIBRARY
#else
#    define SymEncDec_API IMPORT_DYNAMIC_LIBRARY
#endif

#include <memory>
#include <string>

class SymEncDecImpl;

class SymEncDec_API SymEncDec
{
    public:
        explicit SymEncDec();
        explicit SymEncDec(const int&, const int&);
        ~SymEncDec();
            //moveable
        SymEncDec(SymEncDec&& obj) noexcept;
        SymEncDec& operator=(SymEncDec&& obj) noexcept;
            //copyable
        SymEncDec(const SymEncDec& obj);
        SymEncDec& operator=(const SymEncDec& obj);

        void SetKeySize(const int&) ; 
        void SetBlockSize(const int&);

        void SetParams( const std::unique_ptr<unsigned char>&, const std::unique_ptr<unsigned char>&, const unsigned int&, const unsigned int& );
        void GetParams(std::unique_ptr<unsigned char>&, std::unique_ptr<unsigned char>&, unsigned int&, unsigned int&);

        int aes_encrypt (const std::string&, std::unique_ptr<unsigned char>& ) ;
        int aes_decrypt (const std::string&, std::unique_ptr<unsigned char>& ) ;
        int aes_decryptEx (const std::unique_ptr<unsigned char>&, const int&, std::unique_ptr<unsigned char>& );

    private:
         std::unique_ptr<SymEncDecImpl> m_pImpl ;

};

// free function interface
std::unique_ptr<unsigned char> SymEncDec_API KeyGen(std::unique_ptr<unsigned char>&, const unsigned int&, const std::unique_ptr<unsigned char>& , const uint64_t& , const unsigned int& , uint64_t&) ;

#endif /* SYM_ENC_DEC_H */