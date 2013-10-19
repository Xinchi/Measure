
./tsc:     file format elf64-x86-64


Disassembly of section .init:

00000000004003f0 <_init>:
  4003f0:	48 83 ec 08          	sub    $0x8,%rsp
  4003f4:	e8 9b 00 00 00       	callq  400494 <call_gmon_start>
  4003f9:	48 83 c4 08          	add    $0x8,%rsp
  4003fd:	c3                   	retq   

Disassembly of section .plt:

0000000000400400 <__libc_start_main@plt-0x10>:
  400400:	ff 35 02 0c 20 00    	pushq  0x200c02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400406:	ff 25 04 0c 20 00    	jmpq   *0x200c04(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40040c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400410 <__libc_start_main@plt>:
  400410:	ff 25 02 0c 20 00    	jmpq   *0x200c02(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400416:	68 00 00 00 00       	pushq  $0x0
  40041b:	e9 e0 ff ff ff       	jmpq   400400 <_init+0x10>

0000000000400420 <__printf_chk@plt>:
  400420:	ff 25 fa 0b 20 00    	jmpq   *0x200bfa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400426:	68 01 00 00 00       	pushq  $0x1
  40042b:	e9 d0 ff ff ff       	jmpq   400400 <_init+0x10>

Disassembly of section .text:

0000000000400430 <main>:
  400430:	0f 31                	rdtsc  
  400432:	89 d7                	mov    %edx,%edi
  400434:	89 c6                	mov    %eax,%esi
  400436:	0f 31                	rdtsc  
  400438:	48 89 d1             	mov    %rdx,%rcx
  40043b:	48 89 fa             	mov    %rdi,%rdx
  40043e:	89 c0                	mov    %eax,%eax
  400440:	48 c1 e1 20          	shl    $0x20,%rcx
  400444:	48 c1 e2 20          	shl    $0x20,%rdx
  400448:	bf 01 00 00 00       	mov    $0x1,%edi
  40044d:	48 09 f2             	or     %rsi,%rdx
  400450:	48 09 c1             	or     %rax,%rcx
  400453:	be 24 06 40 00       	mov    $0x400624,%esi
  400458:	48 29 d1             	sub    %rdx,%rcx
  40045b:	31 c0                	xor    %eax,%eax
  40045d:	48 89 ca             	mov    %rcx,%rdx
  400460:	e9 bb ff ff ff       	jmpq   400420 <__printf_chk@plt>
  400465:	0f 1f 00             	nopl   (%rax)

0000000000400468 <_start>:
  400468:	31 ed                	xor    %ebp,%ebp
  40046a:	49 89 d1             	mov    %rdx,%r9
  40046d:	5e                   	pop    %rsi
  40046e:	48 89 e2             	mov    %rsp,%rdx
  400471:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400475:	50                   	push   %rax
  400476:	54                   	push   %rsp
  400477:	49 c7 c0 10 06 40 00 	mov    $0x400610,%r8
  40047e:	48 c7 c1 80 05 40 00 	mov    $0x400580,%rcx
  400485:	48 c7 c7 30 04 40 00 	mov    $0x400430,%rdi
  40048c:	e8 7f ff ff ff       	callq  400410 <__libc_start_main@plt>
  400491:	f4                   	hlt    
  400492:	66 90                	xchg   %ax,%ax

0000000000400494 <call_gmon_start>:
  400494:	48 83 ec 08          	sub    $0x8,%rsp
  400498:	48 8b 05 59 0b 20 00 	mov    0x200b59(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  40049f:	48 85 c0             	test   %rax,%rax
  4004a2:	74 02                	je     4004a6 <call_gmon_start+0x12>
  4004a4:	ff d0                	callq  *%rax
  4004a6:	48 83 c4 08          	add    $0x8,%rsp
  4004aa:	c3                   	retq   
  4004ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004004b0 <deregister_tm_clones>:
  4004b0:	b8 3f 10 60 00       	mov    $0x60103f,%eax
  4004b5:	55                   	push   %rbp
  4004b6:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  4004bc:	48 83 f8 0e          	cmp    $0xe,%rax
  4004c0:	48 89 e5             	mov    %rsp,%rbp
  4004c3:	77 02                	ja     4004c7 <deregister_tm_clones+0x17>
  4004c5:	5d                   	pop    %rbp
  4004c6:	c3                   	retq   
  4004c7:	b8 00 00 00 00       	mov    $0x0,%eax
  4004cc:	48 85 c0             	test   %rax,%rax
  4004cf:	74 f4                	je     4004c5 <deregister_tm_clones+0x15>
  4004d1:	5d                   	pop    %rbp
  4004d2:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004d7:	ff e0                	jmpq   *%rax
  4004d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004e0 <register_tm_clones>:
  4004e0:	b8 38 10 60 00       	mov    $0x601038,%eax
  4004e5:	55                   	push   %rbp
  4004e6:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  4004ec:	48 c1 f8 03          	sar    $0x3,%rax
  4004f0:	48 89 e5             	mov    %rsp,%rbp
  4004f3:	48 89 c2             	mov    %rax,%rdx
  4004f6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4004fa:	48 01 d0             	add    %rdx,%rax
  4004fd:	48 89 c6             	mov    %rax,%rsi
  400500:	48 d1 fe             	sar    %rsi
  400503:	75 02                	jne    400507 <register_tm_clones+0x27>
  400505:	5d                   	pop    %rbp
  400506:	c3                   	retq   
  400507:	ba 00 00 00 00       	mov    $0x0,%edx
  40050c:	48 85 d2             	test   %rdx,%rdx
  40050f:	74 f4                	je     400505 <register_tm_clones+0x25>
  400511:	5d                   	pop    %rbp
  400512:	bf 38 10 60 00       	mov    $0x601038,%edi
  400517:	ff e2                	jmpq   *%rdx
  400519:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400520 <__do_global_dtors_aux>:
  400520:	80 3d 11 0b 20 00 00 	cmpb   $0x0,0x200b11(%rip)        # 601038 <__TMC_END__>
  400527:	75 11                	jne    40053a <__do_global_dtors_aux+0x1a>
  400529:	55                   	push   %rbp
  40052a:	48 89 e5             	mov    %rsp,%rbp
  40052d:	e8 7e ff ff ff       	callq  4004b0 <deregister_tm_clones>
  400532:	5d                   	pop    %rbp
  400533:	c6 05 fe 0a 20 00 01 	movb   $0x1,0x200afe(%rip)        # 601038 <__TMC_END__>
  40053a:	f3 c3                	repz retq 
  40053c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400540 <frame_dummy>:
  400540:	48 83 3d d8 08 20 00 	cmpq   $0x0,0x2008d8(%rip)        # 600e20 <__JCR_END__>
  400547:	00 
  400548:	74 1b                	je     400565 <frame_dummy+0x25>
  40054a:	b8 00 00 00 00       	mov    $0x0,%eax
  40054f:	48 85 c0             	test   %rax,%rax
  400552:	74 11                	je     400565 <frame_dummy+0x25>
  400554:	55                   	push   %rbp
  400555:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40055a:	48 89 e5             	mov    %rsp,%rbp
  40055d:	ff d0                	callq  *%rax
  40055f:	5d                   	pop    %rbp
  400560:	e9 7b ff ff ff       	jmpq   4004e0 <register_tm_clones>
  400565:	e9 76 ff ff ff       	jmpq   4004e0 <register_tm_clones>
  40056a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400570 <tsc>:
  400570:	0f 31                	rdtsc  
  400572:	48 c1 e2 20          	shl    $0x20,%rdx
  400576:	89 c0                	mov    %eax,%eax
  400578:	48 09 c2             	or     %rax,%rdx
  40057b:	48 89 d0             	mov    %rdx,%rax
  40057e:	c3                   	retq   
  40057f:	90                   	nop

0000000000400580 <__libc_csu_init>:
  400580:	48 89 6c 24 d8       	mov    %rbp,-0x28(%rsp)
  400585:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
  40058a:	48 8d 2d 87 08 20 00 	lea    0x200887(%rip),%rbp        # 600e18 <__init_array_end>
  400591:	4c 8d 25 78 08 20 00 	lea    0x200878(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400598:	4c 89 6c 24 e8       	mov    %r13,-0x18(%rsp)
  40059d:	4c 89 74 24 f0       	mov    %r14,-0x10(%rsp)
  4005a2:	4c 89 7c 24 f8       	mov    %r15,-0x8(%rsp)
  4005a7:	48 89 5c 24 d0       	mov    %rbx,-0x30(%rsp)
  4005ac:	48 83 ec 38          	sub    $0x38,%rsp
  4005b0:	4c 29 e5             	sub    %r12,%rbp
  4005b3:	41 89 fd             	mov    %edi,%r13d
  4005b6:	49 89 f6             	mov    %rsi,%r14
  4005b9:	48 c1 fd 03          	sar    $0x3,%rbp
  4005bd:	49 89 d7             	mov    %rdx,%r15
  4005c0:	e8 2b fe ff ff       	callq  4003f0 <_init>
  4005c5:	48 85 ed             	test   %rbp,%rbp
  4005c8:	74 1c                	je     4005e6 <__libc_csu_init+0x66>
  4005ca:	31 db                	xor    %ebx,%ebx
  4005cc:	0f 1f 40 00          	nopl   0x0(%rax)
  4005d0:	4c 89 fa             	mov    %r15,%rdx
  4005d3:	4c 89 f6             	mov    %r14,%rsi
  4005d6:	44 89 ef             	mov    %r13d,%edi
  4005d9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005dd:	48 83 c3 01          	add    $0x1,%rbx
  4005e1:	48 39 eb             	cmp    %rbp,%rbx
  4005e4:	75 ea                	jne    4005d0 <__libc_csu_init+0x50>
  4005e6:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  4005eb:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  4005f0:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  4005f5:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  4005fa:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  4005ff:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  400604:	48 83 c4 38          	add    $0x38,%rsp
  400608:	c3                   	retq   
  400609:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400610 <__libc_csu_fini>:
  400610:	f3 c3                	repz retq 
  400612:	66 90                	xchg   %ax,%ax

Disassembly of section .fini:

0000000000400614 <_fini>:
  400614:	48 83 ec 08          	sub    $0x8,%rsp
  400618:	48 83 c4 08          	add    $0x8,%rsp
  40061c:	c3                   	retq   
