// alinhamento obrigatório pelo leiaute dos dados
#define CHUNKSZ_BASE 0x5000

#define CHUNKSZ_TINY   0x1000 + CHUNKSZ_BASE
#define CHUNKSZ_SMALL  0x2000 + CHUNKSZ_BASE
#define CHUNKSZ_MEDIUM 0x4000 + CHUNKSZ_BASE
#define CHUNKSZ_HUGE   0x8000 + CHUNKSZ_BASE


// alinhamento obrigatório pelo leiaute dos dados
static const int chunkSizeBase = 0x5000;

enum ChunkSize
{
   chunkszTiny   = 0x1000 + chunkSizeBase,
   chunkszSmall  = 0x2000 + chunkSizeBase,
   chunkszMedium = 0x4000 + chunkSizeBase,
   chunkszHuge   = 0x8000 + chunkSizeBase,
};


// Fonte original
int main()
{
	// lendo quadro pedaços de dados (tamanho médio)
   ReadChunkFromFile(file, CHUNKSZ_MEDIUM * 4);

	// lendo quadro pedaços de dados (tamanho médio)
   ReadChunkFromFile(file, chunkszMedium * 4);
}


// Pós-processado
int main()
{
	// lendo sei lá o que (perde alinhamento)
   ReadChunkFromFile(file, 0x4000 + CHUNKSZ_BASE * 4);

	// lendo quadro pedaços de dados (tamanho médio)
   ReadChunkFromFile(file, chunkszMedium * 4);
}

