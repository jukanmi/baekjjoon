main(a) {
	while (1) {
		scanf("%d", &a);
		if (!a)break;
		printf("%d\n", a * (a + 1) / 2);
	}
}