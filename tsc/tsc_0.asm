
./tsc:     file format elf64-x86-64


Disassembly of section .init:

00000000004003c8 <_init>:
  4003c8:	48 83 ec 08          	sub    $0x8,%rsp
  4003cc:	e8 6b 00 00 00       	callq  40043c <call_gmon_start>
  4003d1:	48 83 c4 08          	add    $0x8,%rsp
  4003d5:	c3                   	retq   

Disassembly of section .plt:

00000000004003e0 <printf@plt-0x10>:
  4003e0:	ff 35 22 0c 20 00    	pushq  0x200c22(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003e6:	ff 25 24 0c 20 00    	jmpq   *0x200c24(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004003f0 <printf@plt>:
  4003f0:	ff 25 22 0c 20 00    	jmpq   *0x200c22(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003f6:	68 00 00 00 00       	pushq  $0x0
  4003fb:	e9 e0 ff ff ff       	jmpq   4003e0 <_init+0x18>

0000000000400400 <__libc_start_main@plt>:
  400400:	ff 25 1a 0c 20 00    	jmpq   *0x200c1a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400406:	68 01 00 00 00       	pushq  $0x1
  40040b:	e9 d0 ff ff ff       	jmpq   4003e0 <_init+0x18>

Disassembly of section .text:

0000000000400410 <_start>:
  400410:	31 ed                	xor    %ebp,%ebp
  400412:	49 89 d1             	mov    %rdx,%r9
  400415:	5e                   	pop    %rsi
  400416:	48 89 e2             	mov    %rsp,%rdx
  400419:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40041d:	50                   	push   %rax
  40041e:	54                   	push   %rsp
  40041f:	49 c7 c0 10 06 40 00 	mov    $0x400610,%r8
  400426:	48 c7 c1 80 05 40 00 	mov    $0x400580,%rcx
  40042d:	48 c7 c7 3e 05 40 00 	mov    $0x40053e,%rdi
  400434:	e8 c7 ff ff ff       	callq  400400 <__libc_start_main@plt>
  400439:	f4                   	hlt    
  40043a:	66 90                	xchg   %ax,%ax

000000000040043c <call_gmon_start>:
  40043c:	48 83 ec 08          	sub    $0x8,%rsp
  400440:	48 8b 05 b1 0b 20 00 	mov    0x200bb1(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  400447:	48 85 c0             	test   %rax,%rax
  40044a:	74 02                	je     40044e <call_gmon_start+0x12>
  40044c:	ff d0                	callq  *%rax
  40044e:	48 83 c4 08          	add    $0x8,%rsp
  400452:	c3                   	retq   
  400453:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40045a:	00 00 00 
  40045d:	0f 1f 00             	nopl   (%rax)

0000000000400460 <deregister_tm_clones>:
  400460:	b8 3f 10 60 00       	mov    $0x60103f,%eax
  400465:	55                   	push   %rbp
  400466:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  40046c:	48 83 f8 0e          	cmp    $0xe,%rax
  400470:	48 89 e5             	mov    %rsp,%rbp
  400473:	77 02                	ja     400477 <deregister_tm_clones+0x17>
  400475:	5d                   	pop    %rbp
  400476:	c3                   	retq   
  400477:	b8 00 00 00 00       	mov    $0x0,%eax
  40047c:	48 85 c0             	test   %rax,%rax
  40047f:	74 f4                	je     400475 <deregister_tm_clones+0x15>
  400481:	5d                   	pop    %rbp
  400482:	bf 38 10 60 00       	mov    $0x601038,%edi
  400487:	ff e0                	jmpq   *%rax
  400489:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400490 <register_tm_clones>:
  400490:	b8 38 10 60 00       	mov    $0x601038,%eax
  400495:	55                   	push   %rbp
  400496:	48 2d 38 10 60 00    	sub    $0x601038,%rax
  40049c:	48 c1 f8 03          	sar    $0x3,%rax
  4004a0:	48 89 e5             	mov    %rsp,%rbp
  4004a3:	48 89 c2             	mov    %rax,%rdx
  4004a6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4004aa:	48 01 d0             	add    %rdx,%rax
  4004ad:	48 89 c6             	mov    %rax,%rsi
  4004b0:	48 d1 fe             	sar    %rsi
  4004b3:	75 02                	jne    4004b7 <register_tm_clones+0x27>
  4004b5:	5d                   	pop    %rbp
  4004b6:	c3                   	retq   
  4004b7:	ba 00 00 00 00       	mov    $0x0,%edx
  4004bc:	48 85 d2             	test   %rdx,%rdx
  4004bf:	74 f4                	je     4004b5 <register_tm_clones+0x25>
  4004c1:	5d                   	pop    %rbp
  4004c2:	bf 38 10 60 00       	mov    $0x601038,%edi
  4004c7:	ff e2                	jmpq   *%rdx
  4004c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004d0 <__do_global_dtors_aux>:
  4004d0:	80 3d 61 0b 20 00 00 	cmpb   $0x0,0x200b61(%rip)        # 601038 <__TMC_END__>
  4004d7:	75 11                	jne    4004ea <__do_global_dtors_aux+0x1a>
  4004d9:	55                   	push   %rbp
  4004da:	48 89 e5             	mov    %rsp,%rbp
  4004dd:	e8 7e ff ff ff       	callq  400460 <deregister_tm_clones>
  4004e2:	5d                   	pop    %rbp
  4004e3:	c6 05 4e 0b 20 00 01 	movb   $0x1,0x200b4e(%rip)        # 601038 <__TMC_END__>
  4004ea:	f3 c3                	repz retq 
  4004ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004f0 <frame_dummy>:
  4004f0:	48 83 3d 28 09 20 00 	cmpq   $0x0,0x200928(%rip)        # 600e20 <__JCR_END__>
  4004f7:	00 
  4004f8:	74 1b                	je     400515 <frame_dummy+0x25>
  4004fa:	b8 00 00 00 00       	mov    $0x0,%eax
  4004ff:	48 85 c0             	test   %rax,%rax
  400502:	74 11                	je     400515 <frame_dummy+0x25>
  400504:	55                   	push   %rbp
  400505:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40050a:	48 89 e5             	mov    %rsp,%rbp
  40050d:	ff d0                	callq  *%rax
  40050f:	5d                   	pop    %rbp
  400510:	e9 7b ff ff ff       	jmpq   400490 <register_tm_clones>
  400515:	e9 76 ff ff ff       	jmpq   400490 <register_tm_clones>
  40051a:	66 90                	xchg   %ax,%ax

000000000040051c <tsc>:
  40051c:	55                   	push   %rbp
  40051d:	48 89 e5             	mov    %rsp,%rbp
  400520:	41 54                	push   %r12
  400522:	53                   	push   %rbx
  400523:	0f 31                	rdtsc  
  400525:	41 89 d4             	mov    %edx,%r12d
  400528:	89 c3                	mov    %eax,%ebx
  40052a:	44 89 e0             	mov    %r12d,%eax
  40052d:	48 89 c2             	mov    %rax,%rdx
  400530:	48 c1 e2 20          	shl    $0x20,%rdx
  400534:	89 d8                	mov    %ebx,%eax
  400536:	48 09 d0             	or     %rdx,%rax
  400539:	5b                   	pop    %rbx
  40053a:	41 5c                	pop    %r12
  40053c:	5d                   	pop    %rbp
  40053d:	c3                   	retq   

000000000040053e <main>:
  40053e:	55                   	push   %rbp
  40053f:	48 89 e5             	mov    %rsp,%rbp
  400542:	48 83 ec 10          	sub    $0x10,%rsp
  400546:	e8 d1 ff ff ff       	callq  40051c <tsc>
  40054b:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  40054f:	e8 c8 ff ff ff       	callq  40051c <tsc>
  400554:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400558:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40055c:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  400560:	48 89 d1             	mov    %rdx,%rcx
  400563:	48 29 c1             	sub    %rax,%rcx
  400566:	48 89 c8             	mov    %rcx,%rax
  400569:	48 89 c6             	mov    %rax,%rsi
  40056c:	bf 24 06 40 00       	mov    $0x400624,%edi
  400571:	b8 00 00 00 00       	mov    $0x0,%eax
  400576:	e8 75 fe ff ff       	callq  4003f0 <printf@plt>
  40057b:	c9                   	leaveq 
  40057c:	c3                   	retq   
  40057d:	0f 1f 00             	nopl   (%rax)

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
  4005c0:	e8 03 fe ff ff       	callq  4003c8 <_init>
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
