from django.shortcuts import render, redirect
from .models import BookVote

def vote_book(request):
    if request.method == 'POST':
        vote = request.POST.get('vote')
        BookVote.objects.create(vote=vote)
        return redirect('vote_result')
    return render(request, 'vote.html')

def vote_result(request):
    votes = BookVote.objects.all()
    total_votes = votes.count()
    if total_votes == 0:
        percentages = {'good': 0, 'satisfactory': 0, 'bad': 0}
    else:
        percentages = {
            'good': votes.filter(vote='good').count() * 100 / total_votes,
            'satisfactory': votes.filter(vote='satisfactory').count() * 100 / total_votes,
            'bad': votes.filter(vote='bad').count() * 100 / total_votes,
        }
    return render(request, 'vote_result.html', {'percentages': percentages})
