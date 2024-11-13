#ifndef QUEST_HEADER_H_
#error "Footer was included without a header"
#endif /* QUEST_HEADER_H_ */
#undef QUEST_HEADER_H_

/* Reset structure packing at previous byte alignment */
#if defined(_MSC_VER)
#pragma pack(pop)
#endif /* Compiler needs structure packing set */
