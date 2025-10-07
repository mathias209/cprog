int shapeCmp(int shape1, int shape2)
{
    if (shape1 == shape2)
	return -1;
    else if (shape1 == 'r' && (shape2 == 'p' || shape2 == 'o'))
	return 0;
    else if (shape1 == 'p' && (shape2 == 's' || shape2 == 'l'))
	return  0;
    else if (shape1 == 's' && (shape2 == 'r' || shape2 == 'o'))
	return 0;
    else if (shape1 == 'o' && (shape2 == 'p' || shape2 == 'l'))
	return 0;
    else if (shape1 == 'l' && (shape2 == 's' || shape2 == 'r'))
	return 0;
    else
	return 1;
}
